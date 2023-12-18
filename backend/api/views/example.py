from fastapi import APIRouter
from api.services import example as example_svc

example_router = APIRouter(tags=['example'])

example_router.add_api_route("/", example_svc.getExamples, methods=["GET"])
example_router.add_api_route("/{id}", example_svc.getAnExample, methods=["GET"])
example_router.add_api_route("/", example_svc.postExample, methods=["POST"])
example_router.add_api_route("/{id}", example_svc.patchExample, methods=["PATCH"])
example_router.add_api_route("/{id}", example_svc.deleteExample, methods=["DELETE"])