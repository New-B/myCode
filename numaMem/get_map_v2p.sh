#!/bin/bash

# 启动进程（示例：通过 my_program 启动进程）
./alloc_on_particular_numa &

# 获取指定进程的PID（通过名为 my_program 的进程名）
# PID=$(pgrep alloc_on_particular_numa)
PID=$!

# 打印该进程的PID
echo "进程的PID为：$PID"

# 读取该进程的地址映射信息
cat /proc/$PID/maps
