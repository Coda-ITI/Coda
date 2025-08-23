#!/vendor/bin/sh
export PATH=/system/bin:/vendor/bin:$PATH
 
ip addr add 192.168.1.4/24 dev eth0
ip link set eth0 up
ip route add 224.224.224.245 dev eth0

setprop static_ip_done 1