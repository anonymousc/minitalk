# MiniTalk

MiniTalk is a small inter-process communication (IPC) system. It utilizes Unix signals to send and receive
messages between processes. This project is designed to help students understand the basics of signals and process communication in Unix-like operating systems.

## Features

- **Signal-based Communication**: Send and receive messages between processes using Unix signals.
- **Client-Server Architecture**: A simple client-server model where the client sends messages to the server.
- **Message Encoding**: Messages are encoded in binary format for transmission.

## Execution and installation
- **Prerequisites**: clang,glibc-tools,make,unix system. 
- **Run the program**: All you need is to make it, if is showing any issues please leave it in the issues section
### steps are :

```bash
make && ./server&
```
  it will prompt a PID and you can run the client as follows :

```bash
./client "PROMPTED PID" "WHAT DO YOU WANT TO SEND"
```
