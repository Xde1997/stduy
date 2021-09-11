package org.sang.controller;

import org.sang.entity.Book;
import org.sang.service.BookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class BookController {
    @Autowired
    BookService bookService;

    @GetMapping("/findAll")
    public void findAll(){
        PageRequest pageable=PageRequest.of(2,3);
        Page<Book> page=bookService.getBookByPage(pageable);
        System.out .println("总页数： "+page.getTotalPages()) ;
        System.out.println( "总记录数 ：" +page.getTotalElements());
        System.out.println("查询结果："+page.getContent()) ;
        System.out.println("当前页数 ：" +(page.getNumber() +1));
        System.out.println( "当前页记录数："+page.getNumberOfElements());
        System.out.println("每页记录数：" +page.getSize());
    }

    @GetMapping("/save")
    public void save(){
        Book book=new Book();
        book.setAuthor("鲁迅");
        book.setName("呐喊");
        book.setPrice(23F);
        bookService.addBook(book);

    }

}
