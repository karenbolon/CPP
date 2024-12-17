FROM debian:bullseye

#insall nginx and openssl for TLS
RUN apt-get update && \
	apt-get install -y nginx openssl && \
	apt-get clean

COPY ./html5up-story/ /usr/share/nginx/html

#for TLS use port 443 and 80
EXPOSE 80 443

#start NGINX in the foreground
CMD  ["nginx", "-g", "daemon off;"]