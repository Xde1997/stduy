package com.caxa.mall.tiny.service;

import com.caxa.mall.tiny.mbg.model.UmsAdmin;
import com.caxa.mall.tiny.mbg.model.UmsPermission;

import java.util.List;

public interface UmsAdminService {
    UmsAdmin getAdminByUsername(String username);
    UmsAdmin register(UmsAdmin umsAdminParam);

    /**
     * 登录功能
     * @param username 用户名
     * @param password 密码
     * return 生成jwt的token
     */
    String login(String username,String password);

    List<UmsPermission> getPermissionList(Long adminID);
}
