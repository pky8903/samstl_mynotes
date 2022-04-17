//
//  8_coroutine.cpp
//  STL-day5
//
//  Created by Kyoungyoon Park on 2022/04/15.
//

// 8_coroutine1

// 요즘 언어들의 유행
// 1. coroutine, generater
def foo():
    i = 0
    while(1)
        i = i + 1
        yield i

g = foo()
g.next()
g.next()
g.next()

// 2. async, await
ret = await 비동기함수()
