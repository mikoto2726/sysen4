FROM python:3.12

WORKDIR /app
COPY . /app

ENV DJANGO_SETTINGS_MODULE=config.production

RUN pip install -r requirements.txt
RUN python manage.py collectstatic --no-input

EXPOSE 8000

CMD ["gunicorn", "-w", "4", "-b", "0.0.0.0:8000", "config.wsgi:application"]
