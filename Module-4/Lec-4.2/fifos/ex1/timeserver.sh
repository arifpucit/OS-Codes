#!/bin/bash
rm -f /tmp/time_fifo
mkfifo /tmp/time_fifo
while true;
do
    date 1> /tmp/time_fifo
    sleep 1 
done
