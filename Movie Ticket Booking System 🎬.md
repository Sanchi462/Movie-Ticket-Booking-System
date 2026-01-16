# Movie Ticket Booking System 🎬

A simple **console-based Movie Ticket Booking System** developed in C++.  
The program allows users to **view available seats, book seats, and keep track of bookings** using a text file for storage.

## Features
- Displays a **5x10 seat layout** for a movie theater.
- Seats are marked as:
  - `-` : Available
  - `X` : Already booked
- Book a specific seat by entering **row and seat number**.
- **Prevents double booking** of the same seat.
- Saves the seat status to a file (`seats.txt`) so bookings persist even after the program closes.
- Simple **menu-driven interface** with input validation.

## How It Works
1. Run the program.
2. Choose an option:
   - **Book Seat**: Display the seat map and select a seat.
   - **Exit**: Quit the program.
3. Enter the **row (1-5)** and **seat number (1-10)** to reserve a seat.
4. The program updates the seat layout and saves it to `seats.txt`.
   
