use std::Vec;
use std::sync::mpsc;
use std::thread::{self,JoinHandle};
use std::sync::{Arc,Mutex};
pub struct Pool {
    workers: Vec<worker>
    max_workers: usize, //定义最大线程数
    sender: mpsc::Sender<Message>
}

use std::ops::FnOnce;
use std::marker::Send;
impl Pool {
    fn new(max_workers: usize) -> Pool {
        if max_workers==0{
            panic!("max_workers must be greater than zero!")
        }
        let (tx,rx)=mpsc::channel();
        let mut workers=Vec::with_capacity(max_workers);
    }
    fn execute<F>(&self,f:F)where F:FnOnce()+'static+Send {}
}

type Job=Box<dyn FnOnce()+'static+Send>;

enum Message{
    ByeBye,
    NewJob(Job),
}

struct Worker {
    _id: usize,
    t:Option<JoinHandle<()>>,
}
impl Worker{
    fn new(id:usize,receiver:Arc::<Mutex<mspc::receiver<Message>>>)->worker{
        let t=thread::spawn(move||{
            loop{
                let message=receiver.lock().unwrap().recv().unwrap();
                match message{
                    Message::NewJob(job)=>{
                        println!("do job from worker[{}]",id);
                        job();
                    },
                    Message::ByeBye=>{
                        println!("ByeBye from worker[{}]", id);
                        break
                    }
                }
            }
        });

        Worker{
            _id:id,
            t:Some(t),
        }
    }
}