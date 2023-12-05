use crate::schemas::response::Response;
use actix_web::{web, get};

#[get("/")]
pub async fn get_hello_world() -> Response {
    Response{
       status:200,
       message:"hello world".into()
    }
}

#[get("/{name}")]
pub async fn say_hello(path: web::Path<String>) -> Response{
    let name:String = path.into_inner();
    Response{
        status:200,
        message:name
    }
}