use actix_web::{web};
use crate::services::example::*;


pub fn example_view(cfg: &mut web::ServiceConfig){
    cfg.service(web::scope("/example")
        .service(get_examples)
        .service(get_an_example)
        .service(post_an_example)
        .service(patch_an_example)
        .service(delete_an_example)
    );
}