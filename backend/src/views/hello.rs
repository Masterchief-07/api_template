use actix_web::{web, Scope};
use crate::services::hello::get_hello_world;

pub fn hello_views() -> Scope{
    let hello_router = web::scope("/hello")
                    .route("/", web::get().to(get_hello_world));
    hello_router
}