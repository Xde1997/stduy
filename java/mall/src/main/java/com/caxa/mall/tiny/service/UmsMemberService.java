package com.caxa.mall.tiny.service;

import com.caxa.mall.tiny.common.api.CommonResult;

public interface UmsMemberService {
    CommonResult gengerateAuthCode(String telephone);
    CommonResult verifyAuthCode(String telepthone,String authCode);
}
