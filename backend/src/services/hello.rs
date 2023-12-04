use salvo::prelude::handler;

#[handler]
pub async fn get_hello_world() -> &'static str {
    "hello world"
}

#[handler]
pub async fn say_hello() -> &'static str{
    
}