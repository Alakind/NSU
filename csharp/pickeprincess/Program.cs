﻿using database;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Configuration;
using view;
using util;
using model;
using exceptions;

public class Program
{
    public static void Main(string[] args)
    {
        CreateHostBuilder(args).Build().Run();
    }

    public static IHostBuilder CreateHostBuilder(string[] args)
    {
        AttemptData.SetAttemptNumber(args);
        
        return Host.CreateDefaultBuilder(args).ConfigureServices((hostContext, services) =>
        {
            services.AddHostedService<Castle>();
            services.AddScoped<Princess>();
            services.AddScoped<Hall>();
            services.AddScoped<Friend>(); 
            services.AddScoped<ICharacterGenerator, CharacterGenerator>();
            services.AddScoped<ThroneRoom>();
            services.AddScoped<ApplicationContext>();
        });
    }
}
