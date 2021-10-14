import Cookies from 'js-cookie'

export const app={
    state:{
        sidebar:{
            opened: !+Cookies.get('siderbarStatus'),
            withoutAnimation:false
        },
        device: 'desktop'
    },
    mutations:{

    }
}