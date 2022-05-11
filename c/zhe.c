semaphore chopstick[5] = {1,1,1,1,1};
semaphore count = 4; // 设置一个count，最能只能让4个哲学家进房间吃饭
Pi(){
    while(1){
        thinking;
        P(count); // 最多允许4个哲学家进程P操作
        P(chopstick[i]); // 拿起左边的筷子
        P(chopstick[(i + 1) % 5]); // 拿起右边的筷子
        
        eating;
        
        V(chopstick[i]); // 放下左手边的筷子
        V(chopstick[(i + 1) % 5]); // 放下右手边的筷子
        V(count)； // 释放count信号量，允许另外一个没吃到饭的哲学家进房间
    }
}


semaphore mutex = 1;
semaphore chopstick[5] = {1,1,1,1,1};
Pi(){
    while(1){
        thinking;
        P(mutex);
        P(chopstick[i]); // 拿起左边的筷子
        P(chopstick[(i + 1) % 5]); // 拿起右边的筷子
        V(mutex);
        
        eating;
       
        V(chopstick[i]); // 放下左手边的筷子
        V(chopstick[(i + 1) % 5]); // 放下右手边的筷子      
    }
}


semaphore chopstick[5] = {1,1,1,1,1}
Pi(){
    while(1){
        thinking;
        if(i % 2 == 0){ // 偶数号哲学家
            P(chopstick[(i + 1) % 5]); // 先拿右边的筷子
            P(chopstick[i]); // 再拿左边的筷子
            eating;
            V(chopstick[(i + 1) % 5]); // 放下右边的筷子
            V(chopstick[i]); // 放下左边的筷子
        }else{ // 奇数号哲学家
            P(chopstick[i]); // 先拿左边的筷子
            P(chopstick[(i + 1) % 5]); // 再拿右边的筷子
            eating;
            V(chopstick[i]); // 放下左边的筷子
            V(chopstick[(i + 1) % 5]); // 放下右边的筷子
        }
    }
}
