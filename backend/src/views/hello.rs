use actix_web::web;
use crate::services::hello::{
    get_hello_world,
    say_hello,
    }
    ;

pub fn hello_views(cfg: &mut web::ServiceConfig) {
    cfg.service(web::scope("/hello")
                    .route("/", web::get().to(get_hello_world))
                    .route("/{name}", web::get().to(say_hello))
    );
}