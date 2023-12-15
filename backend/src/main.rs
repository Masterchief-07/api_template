mod config;
mod database;
mod schemas;
mod services;
mod views;

use std::env;

use actix_web::{HttpServer, App, web};
use std::env;
use crate::views::hello::hello_views;
use crate::views::example::example_view;
<<<<<<< HEAD
use crate::database::connection::{DbState, create_connexion, create_database, check_connection};
=======
use crate::database::connection::{DbState, create_mysql_connexion, create_database, check_connection};
>>>>>>> 340c755 (making it work on docker-compose)
use crate::views::not_found_default;


#[actix_web::main]
async fn main() -> std::io::Result<()> {
    tracing_subscriber::fmt::init();

    //init database
<<<<<<< HEAD
    let mysql_path = env::var("DATABASE").unwrap();
    print!("{mysql_path}");
    let conn = create_connexion(mysql_path).await.unwrap();
=======
    let conn = create_mysql_connexion(env::var("DATABASE_URL").unwrap()).await.unwrap();
>>>>>>> 340c755 (making it work on docker-compose)
    check_connection(&conn).await;
    // create_database(&conn).await;
    let db_state = DbState{conn};

    HttpServer::new(move || {
        App::new()
        .app_data(web::Data::new(db_state.clone()))
        .configure(hello_views)
        .configure(example_view)
        .default_service(web::to(not_found_default)) //setting default message for unregister path
    })
    .bind(("0.0.0.0", 80))?
    .run()
    .await
}