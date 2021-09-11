package com.caxa.mall.tiny.dao;

import com.caxa.mall.tiny.mbg.model.UmsPermission;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface UmsAdminRoleRelationDao {
    /**
     * 获取用户所有权限
     */
    List<UmsPermission> getPermissionList(@Param("adminId") Long adminId);
}
