package org.sang.component;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonIgnore;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

import java.util.Date;

/**
 * @author xdp
 */
@Component
@ConfigurationProperties(prefix = "book")
public class Book {

    private String name;
    private String author;
    @JsonIgnore
    private Float price;

    @JsonFormat(pattern = "yyyy-MM-dd")
    private Date publicationDate;

    @Override
    public String toString() {
        return "Book{" +
                "name='" + name + '\'' +
                ", author='" + author + '\'' +
                ", price=" + price +
                ", publicationDate=" + publicationDate +
                '}';
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public Float getPrice() {
        return price;
    }

    public void setPrice(Float price) {
        this.price = price;
    }

    public Date getPublicationdate() {
        return publicationDate;
    }

    public void setPublicationdate(Date publicationdate) {
        this.publicationDate = publicationdate;
    }
}
