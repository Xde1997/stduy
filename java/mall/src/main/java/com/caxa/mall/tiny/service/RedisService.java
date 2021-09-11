package com.caxa.mall.tiny.service;

/*
* redis操作Service
* 对象和数组都以json形式进行存储
*
* */
public interface RedisService {
    void set(String key, String value);
    String get(String key);
    boolean expire(String key,long expire);
    void remove(String key);
    Long increment(String key,long delta);
}
