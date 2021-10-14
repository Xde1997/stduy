import Vue from "vue";
import Router from 'vue-router'

Vue.use(Router)

import Layout from '../views/layout/Layout'

export const constantRouterMap=[
    {path:'/login',component: ()=>import('@/views/login/index'),hidden:true},
]