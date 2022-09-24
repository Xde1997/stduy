fn main() {
    let s1 = String::from("hello");

    let len = calculate_length(&s1);

    test(3);

    println!("The length of '{}' is {}.", s1, len);
    Collection::test_vector();
    Collection::test_string();
}

fn calculate_length(s: &String) -> usize {
    s.len()
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter,
}

fn value_in_certs(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => 1,
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter => 25,
    }
}

use std::option::Option;
fn test(max: u8) {
    let config_max = Some(3u8);
    if let Some(max) = config_max {
        println!("The maximum is configured to be {}", max);
    }

    match config_max {
        Some(max) => println!("The maximum is configured to be {}", max),
        _ => (),
    }
}

use std::collections::HashMap;
use std::string::String;
use std::vec::Vec;
mod Collection {
    pub fn test_vector() {
        let mut v: Vec<i32> = Vec::new();
        let v2: Vec<i32> = vec![1, 2, 3];
        v.push(1);
        v.push(2);
        v.push(7);
        v.push(8);

        let third: &i32 = &v2[2];
        println!("The third element is {}", third);

        match v2.get(2) {
            Some(third) => println!("The third element is {}", third),
            None => println!("There is no third element."),
        }
    }

    pub fn test_string() {
        let mut s = String::new();
        s = "initial contents".to_string();
        println!("{}", s);

        let s2 = String::from("initial contents 2");
        println!("{}", s2);

        s.push_str("foo");

        let s3 = String::from("hello");
    }

    use std::collections::HashMap;
    pub fn test_hashmap() {
        let mut scores: HashMap<String, u32> = HashMap::new();
        scores.insert(String::from("Blue"), 10);
        scores.insert(String::from("Yellow"), 20);
    }
}

use std::net::IpAddr;
mod Panic {
    pub fn test_unwrap() {
        use std::net::IpAddr;
        let home: IpAddr = "127.0.0.1".parse().unwrap();
    }
}

mod Generics {
    use std::cmp::PartialOrd;
    pub fn largest<T>(list: &[T]) -> T
    where
        T: Copy + PartialOrd,
    {
        let mut largest = list[0];

        for &item in list {
            if item > largest {
                largest = item;
            }
        }
        largest
    }

    struct Point<T> {
        x: T,
        y: T,
    }

    impl<T> Point<T> {
        fn x(&self) -> &T {
            &self.x
        }
    }

    //特化
    impl Point<f32> {
        fn distance_from_origin(&self) -> f32 {
            (self.x.powi(2) + self.y.powi(2)).sqrt()
        }
    }
}

mod Trait {
    pub trait Summary {
        fn summarize(&self) -> String;
    }
    pub struct NewsArticle {
        pub headline: String,
        pub location: String,
        pub author: String,
        pub content: String,
    }

    impl Summary for NewsArticle {
        fn summarize(&self) -> String {
            format!("{}, by {} ({})", self.headline, self.author, self.location)
        }
    }
}
