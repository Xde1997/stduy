package org.sang.controller;

import org.sang.entity.Author;
import org.sang.entity.Book;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.*;

@RestController
public class HelloController {
    @GetMapping("/hello")
    @ResponseBody
    public List<Object> hello(Model model){
        Map<String, Object> map = model.asMap();
        Set<String> keySet=map.keySet();
        Iterator<String> iterator=keySet.iterator();
        List<Object> list=new ArrayList<>();
        while(iterator.hasNext()){
            String key=iterator.next();
            Object value=map.get(key);
            System.out.println(key+">>>>>"+value);
            list.add(value);
        }
        return list;
    }

    @GetMapping("/book")
    @ResponseBody
    public String book(@ModelAttribute("b") Book book,@ModelAttribute("a") Author author){
        return book.toString()+">>>>"+author.toString();
    }
}
