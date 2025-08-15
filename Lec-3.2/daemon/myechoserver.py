#  Programmer: Arif Butt
#  Course: Operating Systems
#  Writing an echo server in python
#  $ python myechoserver.py &
#  $ nc -u 127.0.0.1 54154
#  If you want to run it as a daemon, the modern way is to use systemctl (write a service unit file)

import socket
sockfd = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sockfd.bind(('0.0.0.0', 54154))
print("My echo server is listening on port: 54154")
while True:
	payload, client_addr = sockfd.recvfrom(1024)
	sockfd.sendto(payload, client_addr)
