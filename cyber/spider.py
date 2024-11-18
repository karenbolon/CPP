import os
import re
import requests
from urllib.parse import urljoin, urlparse
from bs4 import BeautifulSoup
import argparse

SUPPORTED_EXTENSIONS = ('.jpg', '.jpeg', '.png', '.gif', '.bmp')
DEFAULT_PATH = './data/'
DEFAULT_DEPTH = 5


def fetch_page(url):
    """Fetch HTML content from a URL."""
    try:
        response = requests.get(url)
        response.raise_for_status()
        return response.text
    except requests.RequestException as e:
        print(f"Error fetching {url}: {e}")
        return None


def extract_images(html, base_url):
    """Extract image URLs from HTML content."""
    soup = BeautifulSoup(html, 'html.parser')
    images = []
    for img_tag in soup.find_all('img', src=True):
        img_url = urljoin(base_url, img_tag['src'])
        if img_url.endswith(SUPPORTED_EXTENSIONS):
            images.append(img_url)
    return images


def save_image(img_url, save_path):
    """Download and save an image from a URL."""
    try:
        response = requests.get(img_url, stream=True)
        response.raise_for_status()
        filename = os.path.basename(urlparse(img_url).path)
        filepath = os.path.join(save_path, filename)
        with open(filepath, 'wb') as file:
            for chunk in response.iter_content(1024):
                file.write(chunk)
#        print(f"Saved {filename} to {save_path}")
    except requests.RequestException as e:
        print(f"Error downloading {img_url}: {e}")


def spider(url, path, depth, visited=set()):
    """Recursive function to scrape images and traverse links."""
    print(f"Current depth: {depth}")  # Properly indented

    if depth < 0 or url in visited:
        return

    visited.add(url)
    html = fetch_page(url)
    if not html:
        return

    # Save images
    images = extract_images(html, url)
    os.makedirs(path, exist_ok=True)
    for img_url in images:
        save_image(img_url, path)

    # Find and follow links
    soup = BeautifulSoup(html, 'html.parser')
    for a_tag in soup.find_all('a', href=True):
        next_url = urljoin(url, a_tag['href'])
        if urlparse(next_url).netloc == urlparse(url).netloc:  # Stay within domain
            spider(next_url, path, depth - 1, visited)



def main():
    parser = argparse.ArgumentParser(description="Spider: Download images from a website.")
    parser.add_argument("url", help="URL to start scraping from.")
    parser.add_argument("-r", action="store_true", help="Recursively scrape images.")
    parser.add_argument("-l", type=int, help="Maximum depth for recursion.")
    parser.add_argument("-p", type=str, help="Path to save images.")

    args = parser.parse_args()

    url = args.url
    recursive = args.r
    max_depth = args.l if args.l is not None else DEFAULT_DEPTH
    save_path = args.p if args.p else DEFAULT_PATH

    if recursive:
        spider(url, save_path, max_depth)
    else:
        html = fetch_page(url)
        if not html:
            return
        images = extract_images(html, url)
        os.makedirs(save_path, exist_ok=True)
        for img_url in images:
            save_image(img_url, save_path)


if __name__ == "__main__":
    main()
