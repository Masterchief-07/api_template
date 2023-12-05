use actix_web::web;
use crate::services::hello::{
    get_hello_world,
    say_hello,
    }
    ;

pub fn hello_views(cfg: &mut web::ServiceConfig) {
    cfg.service(web::scope("/hello")
                    .service(get_hello_world)
                    .service(say_hello)
    );
}