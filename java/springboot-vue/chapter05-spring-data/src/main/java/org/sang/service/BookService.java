package org.sang.service;

import org.sang.dao.BookDao;
import org.sang.entity.Book;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BookService {
    @Autowired
    BookDao bookDao;
    public void addBook(Book book){
        bookDao.save(book);
    }

    public Page<Book> getBookByPage(Pageable pageable){
        return bookDao.findAll(pageable);
    }

    public List<Book> getBooksByAuthorStartingWith(String author){
        return bookDao.getBooksByAuthorStartingWith(author);
    }

    public List<Book> getBooksByPriceGreaterThan(Float price){
        return bookDao.getBookByPriceGreaterThan(price);
    }

    public Book getMaxIdBook(){
        return bookDao.getMaxIdBook();
    }


}
