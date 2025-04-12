# Computer Networks Lab Programs (KTU CSL332)

This repository contains C implementations of core computer‑networking lab experiments for the APJ Abdul Kalam Technological University (KTU) **CSL332 – Computer Networks Lab**. Each folder simulates a key protocol or algorithm from the course.

---

## 📁 Table of Contents

1. [Leaky Bucket Algorithm](Leaky%20Bucket/leaky_bucket.c)  
2. [Sliding Window Protocols](Sliding%20window%20protocols/)  
   - [Stop‑and‑Wait ARQ](Sliding%20window%20protocols/stop&wait.c)  
   - [Go‑Back‑N ARQ](Sliding%20window%20protocols/GoBack.c)  
   - [Selective Repeat ARQ](Sliding%20window%20protocols/selective_repeat.c)  
3. [Distance Vector Routing (Bellman‑Ford)](Distance%20vector%20routing%20algorithum/distance_vector_routing.c)  
4. [Link State Routing (Dijkstra)](Link%20state/link_state_routing.c)  
5. [Socket Programming](#socket‑programming)  
   - **TCP**  
     - [Simple Message Exchange](TCP/server_communication.c)  
     - [String Reversal](TCP/Reverse_string/server_rev_str.c)  
     - [Prime Number Check](TCP/prime%20number/server_prime.c)  
     - [Factorial Calculator](TCP/factorial/server_factorial.c)  
   - **UDP**  
     - [String Reversal](UDP/reverse_string/server.c)  
     - [Prime Number Check](UDP/prime%20number/server.c)  
     - [Factorial Calculator](UDP/Factorial/server.c)  
6. [Application Protocols](#application‑protocols)  
   - [SMTP (UDP‑based)](SMTP/server.c)  
   - [FTP (TCP‑based)](FTP/server.c)  

---

## Socket Programming

### TCP Programs
- **server_communication.c** / **client_coomunication.c**  
  Basic bidirectional chat over TCP.

- **Reverse_string/**  
  - `server_rev_str.c` / `client_rev_str.c`  
  Reverse a user‑supplied string.

- **prime number/**  
  - `server_prime.c` / `client_prime.c`  
  Check primality of a user‑supplied integer.

- **factorial/**  
  - `server_factorial.c` / `client_factorial.c`  
  Compute factorial of a user‑supplied integer.

### UDP Programs
- **reverse_string/**  
  - `server.c` / `client.c`  
  Reverse a user‑supplied string over UDP.

- **prime number/**  
  - `server.c` / `client.c`  
  Check primality over UDP.

- **Factorial/**  
  - `server.c` / `client.c`  
  Compute factorial over UDP.

---

## Application Protocols

- **SMTP (UDP‑based)**  
  A toy SMTP‑style handshake implemented over UDP:  
  `SMTP/server.c` ↔ `SMTP/client.c`

- **FTP (TCP‑based)**  
  Simple file‑transfer demo:  
  `FTP/server.c` ↔ `FTP/client.c`

---

## How to Use

1. **Clone the repo**  
   ```bash
   git clone https://github.com/Joel-Joshy-V/computer-Networks.git
   cd computer-Networks
