use actix_web::{web, get, post, patch, delete};

use crate::schemas::response::{Response, ResponseData};
use crate::schemas::example::Example;

#[get("/")]
async fn get_examples() -> Response{

    Response{
        status: 200,
        message: "examples".into()
    }
}
#[get("/{id}")]
async fn get_an_example(path: web::Path<u32>) -> Response{
    let _id = path.into_inner();

    Response{
        status: 200,
        message: "examples".into()
    }
}

#[post("/")]
async fn post_an_example(data: web::Json<Example>) -> ResponseData<Example>{
    let info = data.into_inner();

    ResponseData{
        status:201,
        message: "created".into(),
        data: info
    }
}

#[patch("/{id}")]
async fn patch_an_example(path:web::Path<u32>, data: web::Json<Example>) -> ResponseData<Example>{
    let id = path.into_inner();
    let info = data.into_inner();

    ResponseData{
        status:201,
        message: format!("{id} modified"),
        data: info
    }
}

#[delete("/{id}")]
async fn delete_an_example(path:web::Path<u32>) -> Response{
    let id = path.into_inner();

    Response{
        status:201,
        message: format!("{id} deleted")
    }
}