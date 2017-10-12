<!--In order to use this filter, a net_cls control group has to be created first and class as well as process ID(s) assigned to it. The  following  cre‐
ates a net_cls cgroup named "foobar":

  modprobe cls_cgroup
  mkdir /sys/fs/cgroup/net_cls
  mount -t cgroup -onet_cls net_cls /sys/fs/cgroup/net_cls
  mkdir /sys/fs/cgroup/net_cls/foobar

To assign a class ID to the created cgroup, a file named net_cls.classid has to be created which contains the class ID to be assigned as a hexadeci‐
mal, 64bit wide number. The upper 32bits are reserved for the major handle, the remaining hold the minor. So a class ID of e.g.   ff:be  has  to  be
written like so: 0xff00be (leading zeroes may be omitted). To continue the above example, the following assigns class ID 1:2 to foobar cgroup:

  echo 0x10002 > /sys/fs/cgroup/net_cls/foobar/net_cls.classid

Finally some PIDs can be assigned to the given cgroup:

  echo 1234 > /sys/fs/cgroup/net_cls/foobar/tasks
  echo 5678 > /sys/fs/cgroup/net_cls/foobar/tasks

Now by simply attaching a cgroup filter to a qdisc makes packets from PIDs 1234 and 5678 be pushed into class 1:2.-->

# Reference: [Docker & cgroups](http://www.infoq.com/cn/articles/docker-kernel-knowledge-cgroups-resource-isolation)

# Control specified process's cpu resources

+ create a running process with a shell script

  ```
    x=0
    while [ True ];do
      x=$x+1
    done;
  ```

+ check

  `top`

+ control it

  ```
    mkdir -p /cgroup/cpu/foo/   # create a new control group 'foo'
    echo 50000 > /cgroup/cpu/foo/cpu.cfs_quota_us  # set cpu.cfs_quota_us as 50000，just 50% of cpu.cfs_period_us (100000)
    echo 30142 > /cgroup/cpu/foo/tasks
  ```

+ check it again

  `top`

# Control specified process's memory resources

+ create a running process with a shell script

  ```
    x="a"
    while [ True ];do
      x=$x$x
    done;
  ```

+ check

  `top`

+ control it

  ```
    mkdir -p /cgroup/memory/foo
    echo 1048576 >  /cgroup/memory/foo/memory.limit_in_bytes   # give this group 1MB space
    echo 30215 > /cgroup/memory/foo/tasks  
  ```

+ check it again

  `top`

# Control specified process's io resources

+ create a running process

  `dd if=/dev/sda of=/dev/null &`

+ check

  `iotop`

+ control it

  ```
    mkdir -p /cgroup/blkio/foo
    echo '8:0   1048576' >  /cgroup/blkio/foo/blkio.throttle.read_bps_device # 8:0 check from ls -l /dev/sda
    echo 30252 > /cgroup/blkio/foo/tasks
  ```

+ check it again

  `iotop`