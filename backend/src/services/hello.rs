use actix_web::web;

pub async fn get_hello_world() -> &'static str {
    "hello world"
}

pub async fn say_hello(path: web::Path<String>) -> String{
    let name:String = path.into_inner();
    format!("hello {name}")
}