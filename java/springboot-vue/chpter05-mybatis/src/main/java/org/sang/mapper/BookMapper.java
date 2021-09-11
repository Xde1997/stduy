package org.sang.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.sang.entity.Book;

import java.util.List;

@Mapper
public interface BookMapper {
    int addBook(Book book);
    int deleteBookById(Integer id);
    int updateBook(Book book);
    Book getBookById(Integer id);
    List<Book> getAllBooks();
}
