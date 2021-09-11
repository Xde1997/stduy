package org.sang;

import org.springframework.boot.Banner;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.context.annotation.ComponentScan;

/**
 * Hello world!
 *
 * @author xdp
 */
@ComponentScan
@EnableAutoConfiguration
public class App
{
    public static void main( String[] args )
    {
        SpringApplicationBuilder builder=new SpringApplicationBuilder(App.class);
        builder.bannerMode(Banner.Mode.OFF).run(args);
//        SpringApplication.run(App.class,args);

    }
}
