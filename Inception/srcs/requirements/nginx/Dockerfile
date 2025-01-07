# Use an official Debian runtime as a parent image
FROM debian:bullseye

# Set the working directory in the container to /my_folder
WORKDIR /nginx_srcs

#insall nginx and openssl for TLS and any other needed documents/packages
RUN apt-get update && \
	apt-get install -y nginx && \
#	apt-get install -y nginx openssl && \
	apt-get clean

#copy local config files to docker container at /nginx_srcs(relative paths in the docker image)
COPY nginx.conf /etc/nignx/nginx.conf
#COPY torrc /etc/tor/torrc
COPY index.html /usr/share/nginx/html/index.html
#COPY sshd_config /etc/ssh/sshd_config

#for TLS use port 443 and 80 for SSH
#EXPOSE 80 443
EXPOSE 80 443

#start NGINX in the foreground (what should be executed when the container is built/started)
#CMD  ["nginx", "-g", "daemon off;"]
#for local host, we only need nginx to run, once ssh is setup, then we need the -g flag
CMD  ["nginx"]