FROM python:3.11-slim

WORKDIR /app

COPY docker/modules/requirements.txt /app/requirements.txt
RUN pip install --no-cache-dir -r /app/requirements.txt

COPY docker/modules/ ./app/

ENTRYPOINT ["python3"]
CMD ["module_stub.py"]
