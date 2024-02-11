#!/usr/bin/env python
#coding: utf-8

import socket
import sys

clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

port = XXXXX

clientsocket.bind(('', port))
clientsocket.listen(5)

print ('serveur demarre et ecoute sur le port '+str(port))

while 1:
    (serveursocket, address) = clientsocket.accept()
    print("nouvelle connexion a partir de : "+str(address))
    print ("envoie de commandes : ")
    while 1:
        r = str(sys.stdin.readline())

        serveursocket.send(r.encode())

        r = serveursocket.recv(9999)

        client_answer = str(r.decode("utf-8", errors = "ignore"))

        print(str(client_answer)+"\n")
