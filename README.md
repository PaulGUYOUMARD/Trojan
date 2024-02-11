# Trojan horse 

Hi, I'm Paul!
In this repository, I'll show you how to create and use a trojan horse. 

We're going to create an example of a Trojan horse. The victim will be a Windows 10 machine, on which we'll install the server module programmed in C.
On our attacking machine, we'll have the Client module, which will be programmed in Python. We'll be using a Kali Linux operating system based on a Debian OS.
We'll see that once the server module has been installed on the target machine (Windows) and our client module has been installed on our attacking machine (Kali), there will be a connection between the client module and the server module.

Let me remind you how to establish a client/server connection in TCP/IP

To do this, we'll be using TCP connections. Let's take a brief look at TCP protocols, as it's essential to understand this part, as it's vital to the overall understanding of how client/server connections work.TCP stands for transmission control protocol, and is a reliable transport protocol, in connected mode. In the Internet model, it is also called TCP/IP, and TCP is located above IP. In the OSI model, it corresponds to the transport layer (intermediary between the network layer and the session layer). Applications will transmit data streams over a network connection, and TCP will split the data stream into segments whose size depends on the MTU (maximum transmission unit) of the underlying network, i.e. the data link layer. As a reminder, in computer data transmission, the MTU corresponds to the maximum packet size that can be transmitted at one time without fragmentation on an interface. For example, for IPv4, the minimum MTU is 68 bytes, and for IPv6 1280 bytes. Finally, a TCP session is divided into 3 phases, known as the "three-way handshake".

![image](https://github.com/PaulGUYOUMARD/Trojan/assets/120189574/d4787699-a94b-487c-85cb-9cd45819d24f)

In the following order:
- Establishing the connection (3-step handshaking)
- Data transfer
- End of connection
