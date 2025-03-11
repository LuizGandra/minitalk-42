# Minitalk - Inter-Process Communication with Unix Signals

Minitalk is a project from the [42 São Paulo](https://www.42sp.org.br/) Common Core curriculum. It implements a simple communication system between a server and a client using UNIX signals to transmit messages.

![42 São Paulo](https://img.shields.io/badge/42-São_Paulo-black?style=flat-square&logo=42)

## About 42

[42 São Paulo](https://www.42sp.org.br/) is a tuition-free, global coding school emphasizing peer-to-peer learning and project-based education. This project explores signal handling and inter-process communication in C.

## Project Overview

Minitalk consists of two programs: a server and a client. The server receives messages from the client via UNIX signals (`SIGUSR1` and `SIGUSR2`), decoding and displaying them. The client sends messages to the server by converting text into binary signals. It’s divided into:
- **Mandatory Part**: Basic server-client communication.
- **Bonus Part**: Enhanced version with acknowledgment and additional features.

**Note:** Although a bonus directory exists, the mandatory part already fulfills the bonus requirements (e.g., acknowledgment via signals). Thus, the bonus part is merely a duplicate of the mandatory part.

### Key Features

- Server displays received messages instantly.
- Client sends messages to the server using its PID.
- Uses `SIGUSR1` and `SIGUSR2` for bit-by-bit transmission.
- Bonus: server confirms message receipt with a signal back to the client.
- Integrates with `libft` for utility functions.

### Restrictions

- Written in C, compliant with the 42 Norm.
- No unexpected crashes (e.g., segmentation faults).
- No memory leaks from heap allocations.
- Compiled with `-Wall -Wextra -Werror`.
- Relies solely on signals for communication, no shared memory or pipes.

## Getting Started

### Prerequisites

- C compiler (e.g., `clang`).
- `make` utility.
- `libft` library in the project root.

### How to Build and Run

1. Clone the repository:
   
   ```bash
   git clone https://github.com/LuizGandra/minitalk-42.git
   cd minitalk-42

3. Build the mandatory part:
   
   ```bash
   make

4. Build the bonus part (optional):
   
   ```bash
   make bonus

5. Run the server:

   ```bash
   ./server

6. Run the client in a separate terminal:

   ```bash
   ./client <server_pid> <message>

#### Additional commands

- `make clean`: remove object files.
- `make fclean`: remove the program and object files.
- `make re`: rebuild everything.

## Project Structure

- `minitalk.h`: header for mandatory part.
- `src/server.c`: server logic for receiving signals.
- `src/client.c`: client logic for sending signals.
- `minitalk_bonus.h`: header for bonus part.
- `bonus/server_bonus.c`: `src/server.c` copy.
- `bonus/client_bonus.c`: `src/client.c` copy.
- `Makefile`: compilation automation.
- `libft/`: directory for the libft library.

## License

This project is part of the 42 curriculum and intended for educational use.
