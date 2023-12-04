use salvo::prelude::{Router};
use crate::services::hello::get_hello_world;

pub fn hello_views() -> Router{
    let hello_router:Router = Router::with_path("/hello/").get(get_hello_world);
    hello_router
}