use crate::database::connection::DbState;
use crate::database::examples;
use crate::database::examples::Entity as Examples;
use crate::database::examples::Model as examples_models;
use actix_web::Responder;
use actix_web::ResponseError;
use actix_web::{web, get, post, patch, delete};
use sea_orm::ActiveModelTrait;
use sea_orm::EntityTrait;

use crate::schemas::response::{response, response_data};
use crate::schemas::example::Example;

#[get("/")]
async fn get_examples(data: web::Data<DbState>) -> impl Responder{
    let conn = &data.conn;
    let all_examples = Examples::find().all(conn).await.unwrap();
    response_data(
        200,
        "examples".into(),
        Some(all_examples)
    )
}
#[get("/{id}")]
async fn get_an_example(path: web::Path<u32>, data: web::Data<DbState>) -> impl Responder{
    let id = path.into_inner();
    let conn = &data.conn;
    let an_example = Examples::find_by_id(id as i32).one(conn).await.unwrap();
    match an_example{
        Some(e) => {
            response_data(
            200,
            "examples".into(),
            Some(e)
            )
        }
        None => {
            response_data(
                404,
                format!("{id} example not found"),
                None
            )
        }
    }
}

#[post("/")]
async fn post_an_example(example_json: web::Json<Example>, data: web::Data<DbState>) -> impl Responder{
    let conn = &data.conn;
    // let info = example_json.into_inner();
    let ex = examples::ActiveModel::from_json(serde_json::json!(example_json)).unwrap();
    let ex = ex.insert(conn).await.unwrap();

    response_data(
        201,
        "created".into(),
        Some(ex)
    )
}

#[patch("/{id}")]
async fn patch_an_example(id:web::Path<u32>, example_json: web::Json<Example>, data: web::Data<DbState>) -> impl Responder{
    let conn = &data.conn;
    let id = id.into_inner();
    // let info = example_json.into_inner();
    let ex = examples::Entity::find_by_id(id as i32).one(conn).await.unwrap();
    match ex{
        Some(e) =>{
            let mut active_e: examples::ActiveModel = e.into();
            let _ = active_e.set_from_json(serde_json::json!(example_json));
            let e = active_e.update(conn).await.unwrap();
            response_data(
                200,
                format!("{id} example modified"),
                Some(e)
            )
        }
        None =>{
            response_data(
                404,
                format!("{id} example not found"),
                None
            )
        }
    }

}

#[delete("/{id}")]
async fn delete_an_example(id:web::Path<u32>, data: web::Data<DbState>) -> impl Responder{
    let id = id.into_inner();

    let conn = &data.conn;
    let res = examples::Entity::delete_by_id(id as i32).exec(conn).await.unwrap();
    if res.rows_affected != 1 {
        return response(404, format!("{id} example not found"));
    }
    return response(200, format!("{id} example deleted"));

}