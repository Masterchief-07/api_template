use salvo::prelude::{handler, Request};

#[handler]
pub async fn get_hello_world() -> &'static str {
    "hello world"
}

#[handler]
pub async fn say_hello(req: &mut Request) -> &'static str{
   let name = req.params().get("name").cloned().unwrap_or_default();
//    (String::from("hello ") + name.clone()).as_str()
    "asdasd"
}