use sea_orm::{DatabaseConnection, Database, DbErr, ConnectionTrait, Schema};


#[derive(Debug, Clone)]
pub struct DbState{
    pub conn: DatabaseConnection
}

pub async fn create_mysql_connexion(url:String) -> Result<DatabaseConnection, DbErr>{
    let db = Database::connect(url).await?;
    Ok(db)
}

pub async fn create_sqlite_connexion() -> Result<DatabaseConnection, DbErr>{
    // let db: DatabaseConnection = Database::connect("sqlite://./db.sqlite?mode=rwc").await?;
    let db: DatabaseConnection = Database::connect("sqlite::memory:").await?;
    Ok(db)
}

pub async fn check_connection(db: &DatabaseConnection) {
    assert!(db.ping().await.is_ok());
    // db.clone().close().await;
    // assert!(matches!(db.ping().await, Err(DbErr::ConnectionAcquire)));
}

pub async fn create_database(db: &DatabaseConnection) {
    use crate::database::examples;
    let backend = db.get_database_backend();
    let schema = Schema::new(backend);
    let table_create_statement = schema.create_table_from_entity(examples::Entity);
    let _ = db.execute(backend.build(&table_create_statement)).await.unwrap();
}