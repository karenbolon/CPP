
import sys
import os
import argparse
import requests
import time
import random
from bs4 import BeautifulSoup
from urllib.parse import urljoin, urlparse

DEFAULT_DEPTH = 5
DEFAULT_PATH = './data/'
EXTENSIONS = ('.jpg', '.jpeg', '.png', '.gif', '.bmp')

def	polite_delay():
	time.sleep(random.uniform(1,3))


'''
-function gets HTML content from URL
-raise_for_status() is a built in method for checking
status codes
'''
def	fetch_data(url):
	try:
		headers = {
			"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36"
			}
		data = requests.get(url, headers=headers)
		data.raise_for_status()
		return data
	except requests.exceptions.RequestException as e:
		print(f"Error fetching URL {url}: {e}")
		raise SystemExit(e)

'''extracting links'''
def	extract_links(data, base_url):
	link_list = []
	soup = BeautifulSoup(data.content, 'html.parser')
	for tag in soup.find_all('a', href=True):
		href = tag.get('href')
		full_url = urljoin(base_url, href)
		if full_url.startswith("http"):
			link_list.append(full_url)
	return link_list

'''extracting images'''
def	extract_image(data, base_url):
	soup = BeautifulSoup(data.content, 'html.parser')
	image_list = []
	for img in soup.find_all('img', src=True):
		src = img['src']
		img_url = urljoin(base_url, src) #build full URL for image
		if img_url.lower().endswith(EXTENSIONS):
			image_list.append(img_url)
	return image_list


'''download and save image'''
def	saving_images(url, path):
	try:
		data = fetch_data(url)
		if data is None:
			return
		file_name = os.path.basename(urlparse(url).path)
		if not file_name:
			file_name = f"image_{int}.jpg"
		full_path = os.path.join(path, file_name)
		with open(full_path,'wb') as file:
			file.write(data.content)
	except Exception as e:
		print(f"Error saving image {url}: {e}")


'''parse website for links with option for parsing recursively and
download images'''
def parse(url, path, level):
	print(f"parsing level {level}")
	if level <= 0:
		return
	data = fetch_data(url)
	if data is None:
		return
	images = extract_image(data, url)
	for img in images:
		saving_images(img, path)
	#parse links recursively if needed
	if args.recursive:
		links = extract_links(data, url)
		for link in links:#searches for links with anchor tags=href
			if urlparse(link).netloc == urlparse(url).netloc:  # Stay within the same domain
				polite_delay()
				parse(link, path, level - 1)

'''
if __name__=="__main__": ensures the code is only executed
when the script is run directly and not when it's imported
as a module
'''
if __name__=="__main__":
	# Initialize argparse to parse arguments in the terminal
	parser = argparse.ArgumentParser(description="Download images from a URL")
	parser.add_argument("URL", type=str)
	parser.add_argument("-r", "--recursive", action="store_true")
	parser.add_argument("-l", "--level", type=int, default=DEFAULT_DEPTH)
	parser.add_argument("-p", "--path", default=DEFAULT_PATH)
	args = parser.parse_args()

	if not os.path.isdir(args.path):
		os.mkdirs(args.path)
	if args.level <= 0:
		print("Error: Level must be a positive integer.")
		sys.exit(1)
	
	args.path = os.path.abspath(args.path)
	if not args.path.endswith(os.sep):
		args.path += os.sep
	os.makedirs(args.path, exist_ok=True)
	depth_level = args.level
	print(f"URL: {args.URL}, Path: {args.path}, Level: {args.level}, Recursive: {args.recursive}")
	parse(args.URL, args.path, depth_level)

