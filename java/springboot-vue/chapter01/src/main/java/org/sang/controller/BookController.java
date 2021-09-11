package org.sang.controller;

import org.sang.component.Book;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.Date;

/**
 * @author xdp
 */
@RestController
public class BookController {

    @GetMapping("/book")
    @ResponseBody
    public Book book(){
        Book book=new Book();
        book.setAuthor("罗贯中");
        book.setName("三国演义");
        book.setPrice(30f);
        book.setPublicationdate(new Date());
        return book;
    }
}
