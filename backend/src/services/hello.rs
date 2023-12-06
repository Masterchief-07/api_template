use crate::schemas::response::response;
use actix_web::{web, get, Responder};

#[get("/")]
pub async fn get_hello_world() -> impl Responder {
    response(
       200,
       "hello world".into(),
    )
}

#[get("/{name}")]
pub async fn say_hello(path: web::Path<String>) -> impl Responder{
    let name:String = path.into_inner();
    response(
        200,
        name,
    )
}