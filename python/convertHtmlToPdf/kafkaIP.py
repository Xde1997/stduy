from pykafka import KafkaClient
import socket
client=KafkaClient(hosts="192.168.0.178:9092")
print(client.topics)
print(client.brokers)
for n in client.brokers:
    host = client.brokers[n].host
    addr = socket.gethostbyname(host)
    port = client.brokers[n].port
    id = client.brokers[n].id
    print(type(id))
    print("host=%s|port=%s|broker.id=%s" % (addr, port, id))