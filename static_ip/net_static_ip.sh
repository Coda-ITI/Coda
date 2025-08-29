#!/system/bin/sh
set -ex
exec 2>/data/local/tmp/net_static_ip.log

PATH=/system/bin:/vendor/bin
log -t net-init "Waiting for eth0..."
while [ ! -d /sys/class/net/eth0 ]; do sleep 0.5; done
log -t net-init "eth0 found"

ip link set dev eth0 up || true
sleep 1
ip addr flush dev eth0 || true
ip addr add 192.168.1.4/24 dev eth0
ip route add 224.224.224.245 dev eth0 || true
log -t net-init "Static IP set"


setprop static_ip.done 1
