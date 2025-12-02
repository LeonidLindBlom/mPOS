import json
import os
import socket
import sys

HOST = os.getenv("EVENT_HOST", "127.0.0.1")
PORT = int(os.getenv("EVENT_PORT", "28090"))

def send(event):
    data = json.dumps(event).encode() + b"\n"
    sock.sendall(data)
    print("->", event)

def main():
    global sock
    sock = socket.create_connection((HOST, PORT))
    sequence = [
        {"type":"Heartbeat","network":1,"ping":1,"power":1,
         "seq":1,"signal":88,"mv":3920,"soc":82,"droop":1},
        {"type":"SetAmount","amount":12345,"currency":"RUB"},
        {"type":"CardData","emvOk":1,
         "pan":"4256********9310","expiry":"2712","holder":"CARDHOLDER"},
        {"type":"PinEntered"},
        {"type":"BankResponse","approved":1,"seq":1,"latency":95},
        {"type":"UpdateRequest","role":"operator"},
        {"type":"UpdatePayload","version":"1.0.1","size":1048576,"chunk":1,"chunks":2,"sig":1},
        {"type":"UpdatePayload","version":"1.0.1","size":1048576,"chunk":2,"chunks":2,"sig":1},
        {"type":"UpdateVerify","sig":1},
        {"type":"UpdateInstall","ok":1}
    ]
    for evt in sequence:
        send(evt)
    sock.close()

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
