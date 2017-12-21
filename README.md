# QZMQ
QZMQ是基于消息队列之ZMQ（C++）搭建的基础框架

ZeroMQ概述：

ZeroMQ是一种基于消息队列的多线程网络库，其对套接字类型，连接处理，帧，甚至路由的底层细节进行抽象，提供跨越多种传输协议的套接字.ZeroMQ是网络通信中新的一层，介于应用层和传输层之间（按照TCP / IP划分），其是一个可伸缩层，可并行运行，分散在分布式系统间; 

ZeroMQ系统架构：

ZeroMQ几乎所有的I/O操作都是异步的，主线程不会被阻塞。ZeroMQ会根据用户调用zmq_init函数时传入的接口参数，创建对应数量的I/O Thread。每个I/O Thread都有与之绑定的Poller，Poller采用经典的Reactor模式实现，Poller根据不同操作系统平台使用不同的网络I/O模型（select、poll、epoll、devpoll、kequeue等）。主线程与I/O线程通过Mail Box传递消息来进行通信。Server开始监听或者Client发起连接时，在主线程中创建zmq_connecter或zmq_listener，通过Mail Box发消息的形式将其绑定到I/O线程，I/O线程会把zmq_connecter或zmq_listener添加到Poller中用以侦听读/写事件。Server与Client在第一次通信时，会创建zmq_init来发送identity，用以进行认证。认证结束后，双方会为此次连接创建Session，以后双方就通过Session进行通信。每个Session都会关联到相应的读/写管道， 主线程收发消息只是分别从管道中读/写数据。Session并不实际跟kernel交换I/O数据，而是通过plugin到Session中的Engine来与kernel交换I/O数据。

ZeroMQ消息模式：

ZeroMQ将消息通信分成4种模型，分别是一对一结对模型（Exclusive-Pair）、请求回应模型（Request-Reply）、发布订阅模型（Publish-Subscribe）、推拉模型（Push-Pull）。这4种模型总结出了通用的网络通信模型，在实际中可以根据应用需要，组合其中的2种或多种模型来形成自己的解决方案。

