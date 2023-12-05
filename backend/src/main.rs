mod database;
mod schemas;
mod services;
mod views;
use actix_web::{HttpServer, App};
use crate::views::hello::hello_views;
use crate::views::example::example_view;

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
        .configure(hello_views)
        .configure(example_view)
    })
    .bind(("127.0.0.1", 8001))?
    .run()
    .await
}