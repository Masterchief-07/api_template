use actix_web::{web, get};

#[get("/")]
pub async fn get_hello_world() -> &'static str {
    "hello world"
}

#[get("/{name}")]
pub async fn say_hello(path: web::Path<String>) -> String{
    let name:String = path.into_inner();
    format!("hello {name}")
}