// RayTracing_from_scratch.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include "RayTracing_from_scratch.h"
#include "Renderer.h"
#include <ctime>
#include <random>

int square_size = 2;

//using namespace Eigen;
Eigen::Vector3f get_sky_colour(Eigen::Vector3f ray_dir) {
	return Eigen::Vector3f(0.5f, 0.7f, 1.0f) * (0.6f - ray_dir.y());
}


int main()
 {
	std::srand((unsigned int)time(0));
	Renderer::PinholeCamera cam;// (256, 256);
	cam.setPosition(Eigen::Vector3f(4.0f, 2.0f, 4.0f));
	
	cam.lookAt(Eigen::Vector3f(1.0f, 0.0f, 0.0f));
	Renderer::SceneLoader loader("D:\\Users\\Brayner\\UFPE\\Voxar\\RayTracer\\Models\\Cubes\\Cubes.obj");
	//Renderer::SceneLoader loader("D:\\3Dprojects\\Table_and_Chair\\table.obj");
	std::cout << "Assimp loaded" << std::endl;
	loader.convertAssimpScene();
	std::cout << "Scene converted" << std::endl;
	// Scene
	Renderer::Scene scene = loader.getRendererScene();
	scene.setCamera(cam);
	// Ground
	Renderer::Object* ground = new Renderer::GroundPlane(Eigen::Vector3f(0.0f, 0.0f, 0.0f) , -0.5f, true);
	ground->setColor(Eigen::Vector3f(0.0f, 0.0f, 0.0f));
	ground->name = "ground";
	scene.insertObject(ground);
	// Ligh
	Renderer::Light* newlight = new Renderer::Light(Eigen::Vector3f(1.0f, 1.0f, 1.0f));
	newlight->setPosition(Eigen::Vector3f(0.0f, 50.0f, 50.0f));
	scene.insertLight(newlight);
	//scene.insertObject(new Triangle(Eigen::Vector3f(-1, 0, 0), Eigen::Vector3f(1, 0, 0), Eigen::Vector3f(0, 1.73, 0)));
	//scene.insertObject(new Renderer::Triangle(Eigen::Vector3f(-1.0f, 0.0f, -8.0f), Eigen::Vector3f(0.0f, 1.73f, -8.0f), Eigen::Vector3f(1.0f, 0.0f, -8.0f)));
	
	std::cout << "rendering" << std::endl;

	//std::random_device rd;
	//std::mt19937 gen(rd());  //here you could set the seed, but std::random_device already does that
	//std::uniform_real_distribution<float> dis(-1.0, 1.0);
	//std::cout << "Rand: " << (Eigen::Vector3f::NullaryExpr([&]() {return dis(gen); }).normalized())*0.0001f << std::endl;
	//std::cout << "Rand: " << (Eigen::Vector3f::NullaryExpr([&]() {return dis(gen); }).normalized())*0.0001f << std::endl;
	//std::cout << "Rand: " << (Eigen::Vector3f::NullaryExpr([&]() {return dis(gen); }).normalized())*0.0001f << std::endl;
	//std::cout << "Rand: " << (Eigen::Vector3f::NullaryExpr([&]() {return dis(gen); }).normalized())*0.0001f << std::endl;
	//std::cout << "Rand: " << (Eigen::Vector3f::NullaryExpr([&]() {return dis(gen); }).normalized())*0.0001f << std::endl;
	//std::cout << "Rand: " << (Eigen::Vector3f::NullaryExpr([&]() {return dis(gen); }).normalized())*0.0001f << std::endl;

	std::clock_t start = std::clock();

	scene.renderSceneOnPPM("img.ppm");

	float duration = (std::clock() - start) / (float)CLOCKS_PER_SEC;
	std::cout << "rendered in " << duration << " seconds" << std::endl;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
