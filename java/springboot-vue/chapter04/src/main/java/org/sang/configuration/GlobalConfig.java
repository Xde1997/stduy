package org.sang.configuration;

import org.springframework.web.bind.WebDataBinder;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.InitBinder;
import org.springframework.web.bind.annotation.ModelAttribute;

import java.util.HashMap;
import java.util.Map;

/**
 * @author xdp
 */
@ControllerAdvice
public class GlobalConfig {
    @ModelAttribute(value = "info")
    public Map<String,String> userInfo(){
        HashMap<String,String> map=new HashMap<>();
        map.put("username","罗贯中");
        map.put("gender","男");
        return map;
    }

    @InitBinder("b")
    public void init_b(WebDataBinder binder){
        binder.setFieldDefaultPrefix("b.");
    }

    @InitBinder("a")
    public void init_a(WebDataBinder binder){
        binder.setFieldDefaultPrefix("a.");
    }
}
